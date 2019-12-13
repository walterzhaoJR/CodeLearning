/***
 * tdsql vector
 * walterzhao
 * 2019.6.29
 ***/

#pragma once

#include <memory>

template <typename T>
class TDVector
{
 public:
  using iterator = T*;
  using const_iterator = const T*;
 public:
  TDVector() = default;
  ~TDVector();
 public:
  inline iterator Begin() const{ return start_ptr_; }
  inline iterator End() const{ return end_ptr_; }
  inline int64_t Size() const{ return end_ptr_ - start_ptr_; }
  inline int64_t Capacity() const {return cap_ptr_ - start_ptr_; } 
  inline bool Empty() const { return 0 == Size(); }
  T& operator[](int64_t i) const;
  T& At(int64_t i) const;
  void PushBack(const T& new_elem);
  void PopBack();
  iterator Erase(const_iterator position);
  iterator Erase(const_iterator first, const_iterator last);
private:
  iterator start_ptr_ = NULL;
  iterator end_ptr_ = NULL;
  iterator cap_ptr_ = NULL;
  std::allocator<T> alloc_;
 private:
    void CheckCap_();
    void Free_();
};

template<typename T>
TDVector<T>::~TDVector(){
  Free_();
}

template<typename T>
void TDVector<T>::Free_(){
  if (start_ptr_){
    for (auto i = start_ptr_; i != end_ptr_; ++i){
      alloc_.destroy(i);
    }
    
    alloc_.deallocate(start_ptr_, end_ptr_ - start_ptr_);
  }
}

template<typename T>
T& TDVector<T>::operator[](int64_t i) const{
	return At(i);
}

template<typename T>
T& TDVector<T>::At(int64_t i) const{
  //TD_ASSERT((0 <= i) && (start_ptr_ + i < end_ptr_));
  return *(start_ptr_ + i);
}

template<typename T>
void TDVector<T>::CheckCap_(){
  if (end_ptr_ == cap_ptr_){
    int64_t new_size = Size() ? Size() * 2 : 1;
    auto new_start_ptr = alloc_.allocate(new_size);
    auto new_end_ptr = uninitialized_copy(std::make_move_iterator(start_ptr_), std::make_move_iterator(end_ptr_), new_start_ptr);
    Free_();
    start_ptr_ = new_start_ptr;
    end_ptr_ = new_end_ptr;
    cap_ptr_ = new_start_ptr + new_size;
  }
}

template<typename T>
void TDVector<T>::PushBack(const T& new_elem){
  CheckCap_();
  alloc_.construct(end_ptr_, new_elem);
  end_ptr_++;
}

template<typename T>
void TDVector<T>::PopBack(){
  if (end_ptr_ - start_ptr_ > 0){
    alloc_.destroy(end_ptr_);
    end_ptr_--;
  }
}

template<typename T>
typename TDVector<T>::iterator TDVector<T>::Erase(const_iterator first, const_iterator last){
  //TD_ASSERT((first >= start_ptr_) && (last < end_ptr_));
  iterator new_end_ptr = std::copy(last, static_cast<const_iterator>(end_ptr_), first);
  
  while(new_end_ptr < end_ptr_){
    alloc_.destroy(--end_ptr_);
  }
  
  return end_ptr_;
}

template<typename T>
typename TDVector<T>::iterator TDVector<T>::Erase(const_iterator position){
  return Erase(position, position + 1);
}

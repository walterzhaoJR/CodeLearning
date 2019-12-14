#/bin/bash 
start=$(date +%s)
sleep 10
end=$(date +%s)
diff=$(( end - start ))
echo $diff

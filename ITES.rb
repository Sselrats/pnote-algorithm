$_a = 1983
$array = Queue.new
$current = 1984
$k = 0
$n = 0
$count = 0
$sum = 0
$status = :same

def calc
 while $to <= $n do
   if $status == :needpush || :needboth
     $current = $_a % 10000.0 + 1
     $_a = ($_a * 214013 + 2531011) % 4294967296.0
     $sum = $sum + $array.push($current)
   end
   if $status == :needpush || :needboth
     $sum = $sum - $array.pop
   end
   if $sum > $k
     $status = :needpop
   end
   elsif $sum == $k
     $count += 1
     $status = :needboth
   elsif $sum < $k
     $status = :needpush
   end
 end
end

Integer(gets).times do
 kn = gets.chomp
 kn = kn.strip.split
 $k = Integer(kn[0])
 $n = Integer(kn[1])
 $_a = 1983
 $array = Queue.new
 $current = 1984
 $count = 0
 $status = :needpush
 calc
 puts $count
end
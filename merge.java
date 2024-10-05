class Solution {
    public int[][] merge(int[][] intervals) {
        int len=intervals.length;
        List<List<Integer>> list=new ArrayList<>();
        Arrays.sort(intervals , (a,b) -> a[0]==b[0] ? a[1]-b[1] : a[0]-b[0] );
        int i;
        int start=intervals[0][0];
        int end =intervals[0][1];
        for(i=1;i<len;i++){
            List<Integer> sub=new ArrayList<>();
            if(intervals[i][0]>end){
                sub.add(start);
                sub.add(end);
                list.add(sub);
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                end=Math.max(end,intervals[i][1]);
            }
            
        }
        List<Integer> sub=new ArrayList<>();
        sub.add(start);
        sub.add(end);
        list.add(sub);
        
        
        int size=list.size();
        int[][] res=new int[size][2];
        
        for(i=0;i<size;i++){
            res[i][0]=list.get(i).get(0);
            res[i][1]=list.get(i).get(1);
        }
        return res;
    }
}

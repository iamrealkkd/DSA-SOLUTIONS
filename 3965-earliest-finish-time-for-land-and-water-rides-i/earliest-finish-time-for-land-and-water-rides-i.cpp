class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {

            for (int j = 0; j < waterStartTime.size(); j++) {

                // Land -> Water
                int landFinish = landStartTime[i] + landDuration[i];

                int waterStart = max(landFinish, waterStartTime[j]);

                int waterFinish = waterStart + waterDuration[j];

                ans = min(ans, waterFinish);


                // Water -> Land
                int waterFinishFirst =
                    waterStartTime[j] + waterDuration[j];

                int landStart =
                    max(waterFinishFirst, landStartTime[i]);

                int landFinishSecond =
                    landStart + landDuration[i];

                ans = min(ans, landFinishSecond);
            }
        }

        return ans;
    }
};
// story:jiuyang ������

#include <ansi.h>

static string char_id;
static string char_name;

int give_gift();
object select_character();

mixed *story = ({
        "һ�ѷ𾭡�",
        "��������һ��ϸϸ�Ŀ��˰��죬ȴ����Ҫ�죬���������һ���𾭣�û�а���书���ϡ�",
        "���˳�˼Ƭ�̣����鷴�˹��������������ֶ�������û��ʲô���",
        "ʢŭ֮�£����������������˿�ȥ���ּ���һ����ȴ�ǡ���վ�����",
        "�ж�Ƭ�̣�����һ�ѷϻ���",
        "�����д��������µĲؾ���ͷ�����Щ���������������а�������Ī������ɮ����ʵ�������书����",
        "����涪�������Ѿ����˼�ʮ�����飬û���ҵ����ͷ����",
        "���˲��ɵð����п࣬���˿��������ŵĻ���͵�һ���ˣ����룺��δ����ؾ���ʵ���Ǹ�ð���գ���Ȼ...",
        "һʱ�����˲��ɵ���ͷ��ŭ�������еľ���˺�˸����飬��ʱֽƬ���",
        "��Ȼ������ֽƬƮ�����˵���ǰ���ƺ�д�ţ������˽裬���ɼ������������ɼ���...",
        "���˼�ʶ�����������⼸�����е�ʱһ����������Ǽ��ϳ˵���ѧ���ϣ�",
        "���˿��˿�����ʣ�µİ���飬��Ȼ��һ��������٤������ֻ���з������������д��һЩ���֡�",
        "ֻ�Ǿ����Ѿ�ȱ��һ�룬����Ǻã�������æ�ڵ�������Ѱ�ң�����ֽһƬƬѰ�ء�",
        "������ƬϤ���Ѻã���Ȼ��������ʱ��������ϸϸ������ԭ���⡶��٤�����з��о�Ȼ¼��һ�ݾ����澭��",
        "�������°�����ĥ�����껪ɽ�۽���Ҳ����������һ�������澭���ѣ������ҵ��˴��飬������������",
        "�����漴����̨�ý���������Ħ�澭Ҫּ��ֻ���澭�����һʱδ��ȫȻ����",
        "�ۼ���ɫ�������˲��Ҿ����������飬�����룬�ְѾ��Ŀ�ͷһ�γ���˺�飬����պá�",
        "���˰��������һ�ȥϸϸ�ж�������澭�����������޵У������գ�",
        "��գ�����Ծ����ȥ����ȻƮʧ��ҹĻ�С�",
        (: give_gift :),
});

string prompt() { return HIG "������������" NOR; }

void create()
{
        seteuid(getuid());
}



mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
         
        int i;
        object env,ob;
        object *players;
        string msg;

        players = users();
        if (sizeof(players) >= 10)
        {
                for (i = 0; i < 10; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                        if (ob->query("family/family_name")!="����") continue;
                        if (!ob->query_skill("jiuyang-shengong", 1)) continue;
                        if (ob->query("story/jiuyang")) continue;                        
                                
                }
if(!ob) return 1;
if ((int)ob->query_skill("jiuyang-shengong", 1) >1)
{
        if (ob->query_skill("jiuyang-shengong", 1) < 100)
                ob->set_skill("jiuyang-shengong", 100);
}
        ob->set("story/jiuyang", 1);
if (ob)
{
tell_object(ob, HIC "��ѧϰ���˾����񹦡�\n" NOR);
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵������"
                              "�ؾ���ʧ�ԣ���ʧ��٤��һ����");
}
        STORY_D->remove_story("new13");
      }
        return 1;
}

// story:huanyin ����ָ��

#include <ansi.h>

static string char_id;
static string char_name;
static string family_name;

int give_gift();
object select_character();

mixed *story = ({
        "лѷ�����������ߣ������Ҿͺ�����һ�˶�",
        "�����������̵ģ�����������Ϲ�ӣ����ҵ�ù�����ˡ�",
        "���У��������������ˣ����������������컹����ô��",
        "ΤһЦ����������������黹û���˰��������ô���ˣ�",
        "���޼ɺ���һ�����������常��������Ѫ����𣬲��ܲ������ҵ����ز��֡�",
        "�����ǺǴ�Ц���Ϸ������������ǣ�ֻ���������ж�ȡʤ���Ϸ�Ͳ��ܷ����ˡ�",
        "ΤһЦЦ������������ʹ���������ܴ�Ӯʨ������������·�����Ǿ������֡�",
        "������Цһ���������Ϸ���˼�ʮ�꣬��Ȼ��������ǰ������С���ƣ�",
        "ΤһЦ���������Ǿͱ����...",
        "ֻ��ΤһЦ����ٿ�ı�죬ֱ���˷�����˼��˫���ߵó����������һ��������������...",
        "�����������������ӣ�ΤһЦ��Ҳ���ˣ�ֻ����������������ȴ��ô�������",
        "��Ȼ·��һ��ƮȻ���������ţ�����Ϊ�Σ���",
        "ΤһЦһ��̽�����������ˣ��ȵ������ÿ�����",
        "�����ȵ�����������˺ݶ������Ҳ����ʲô���ࡣ���漴һ������ӳ���",
        "�����ཻ��ֻ���ΤһЦ�ۻ����ң���Ѫ��ӿ����ƽƽ�ķ��˳�ȥ��һ��ˤ���ڵء�",
        "���޼ɼ�״�󾪣���æ�����������סΤһЦ��",
        "����������Ц�������Ž���������ʹ��Τ���������ҵú�ͽ���������ҿ�Ҫʧ���ˡ�",
        "���޼ɺȵ������º��ˣ�Ϊ��Ҫ���ִ��£�",
        "���˵����������������޶���������һ����������Ȼ���ұ������ˣ������������������Ͼ��ǡ�",
        "���޼ɣ�@@@@@@@",
        "......",
        "���������������ȣ��Ϸ�м�����������Ϊ������·����ָ�������¾��У�����������⣬Ҳ�ɲ���һ����",
        (: give_gift :),
});

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
                        if (ob->query("story/jiuyang")) continue;                        
                                
                }
if(!ob) return 1;
        if (ob->query_skill("xuantian-zhi", 1) < 100)
                ob->set_skill("xuantian-zhi", 100);

        ob->set("story/jiuyang", 1);
if (ob)
{
tell_object(ob, HIC "��ӳ�������ѧϰ���˻���ָ��֮��������ָ��\n" NOR);
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + ob->name(1) +
                              "�ӳ�������ѧϰ���˻���ָ��֮��������ָ��");
}
        STORY_D->remove_story("new14");
      }
        return 1;
}




// story:shenzhao ��Ѫ��צ

#include <ansi.h>

int give_gift();


mixed *story = ({
        "�󺵣��񼢡�",
        "�����糱��",
        "��÷����������·�����ࡣ",
        "��ɫ�����ۼ������ཫ����",
        "ֻ��·��ҡҡ�λ��߹���һ�ˡ�",
        "��÷�������һ���࣬�͵������...��",
        "��Ȼ�䷢������ͷ���ڽ���Ȼ�ƾɣ�ȴ���������롣",
        "��÷���а������ɲ�Ҫ��һ������ӣ����������һ�����Ͳ���ȥ��",
        "�뵽����㽫�Ǹ���ְ������¶��ӣ�������������λ�������������������ࡣ��",
        "���˿��˿���÷���м�������һ·����Ϊ��������̼��������벻������������λ���ˡ���",
        "��÷��������Ȼ�Ǹ�����ӣ����ã����á�",
        "...",
        "���˺����࣬�ͳ�һ���������õ��飬�ݸ���÷��",
        "��÷��...",
        "���˵��������ɴ��࣬�����������Ȿ�������͸������ɡ���",
        "......",
        "�ۼ��������Ƕ�ȥ����÷���˷����е��飬��Ц��ֹ��",
        "���Ҵ��ֲ�ʶһ����Ҫ���������������뵽�����÷��������һ�����������·��",
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
                object gob;
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
                                
                }
        if(!ob) return 1;
        gob = new(__DIR__"obj/mengzi");
        gob->move(ob, 1);
 if (ob)
{
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + ob->name(1) +
                              "�������顶���ӡ���");
}
        STORY_D->remove_story("new11");
      }
        return 1;
}
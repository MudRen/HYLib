// story:shenzhao ��Ѫ��צ

#include <ansi.h>

int give_gift();


mixed *story = ({
        "��ĸ����...����ɶ��",
        "�׹�����ô���㣿",
        "��ĸ��ĿԲ�������д�����˵���㱳���ﶼ�����Ҹ�Щʲô��",
        "�׹�����̬��",
        "��ĸ����...",
        "...",
        "��...",
        "����...",
        "���ƣ�������������������������������",
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
        if (ob->query("gift/lighting") || random(5))
        {
        CHANNEL_D->do_channel(this_object(), "rumor", HIR"ֻ��" +ob->name(1) +
                              "һ���ҽУ�����ĵ�����ȥ��"NOR);
//                msg = HIR + ob->name(1) + "һ���ҽУ�����ĵ�����ȥ��" NOR;
                if (ob->query("combat_exp") < 1000000 ||
                    ob->query("qi") < 1000)
                        ob->unconcious();
                else
                {
                        ob->set("qi", 10);
                        ob->set("eff_qi", 10);
                        ob->set("jing", 1);
                        ob->set("eff_jing", 1);
                }
        } else
        {
if (ob)
{
        CHANNEL_D->do_channel(this_object(), "rumor", HIC"���Ǽ�" +ob->name(1) +
                              "��������䣬��������һ�㣬�������ݡ�"NOR);
}
//                msg = HIC "���Ǽ�" + ob->name(1) + "��������䣬��������һ�㣬�������ݡ�" NOR;
                ob->add("con", 1);
                ob->add("gift/lighting", 1);
        }
//        message_vision(msg);
//
//        return msg;

if (ob)
{
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + ob->name(1) +
                              "���״����ˡ�");
}
        STORY_D->remove_story("new12");
      }
        return 1;
}
// queststone.c written by john darks
#include <ansi.h>
inherit EQUIP;
int time_period(int timep, object me);

void create()
{
        set_name("����ʱ��̽����", ({ "questtime","detector", "glass", "device" }) );
        set_weight(300);
        set("unit", "��");
        set("long",
                "�������ԡ������项��ս����̽���������������װ��һ�£����������������\n"
                "̽��(questtime)�й��������ɶ��ˡ�\n");
        set("value", 500);
        set("no_drop",1);
        set("type", "misc");
        set("apply", ([
                "ͷ��": 0,
        ]) );
}

void init()
{
        add_action("do_detect", "questtime");
}

int do_detect(string arg)
{
        int nowtime = time();
        int i;
        object me;
        object ob = this_player();
        if (!wizardp(ob) || arg == "") me = ob;
        else
        {
                if( arg ){
                        me = present(arg, environment(ob));
                        if (!me) me =  find_player(arg);
                        if (!me) return notify_fail("��Ҫ�쿴˭������\n");
                }
                else
                        me = ob;
        }
        if(!me->query("wqrquest") && !me->query("quest"))
                return notify_fail("������û���κ�����\n");
        if( mapp(me->query("wqrquest")))
        {
                mapping quest;
                quest =  me->query("wqrquest");
                write("�����������������������" + quest["quest_type"] + "��" + quest["quest"] + "����\n");
                nowtime = (int) me->query("wangqier/time") - time();
                if( nowtime  > 0 )
                        time_period(nowtime, me);
                else
                        write("�������Ѿ�û���㹻��ʱ����������ˡ�\n");
        }
        if( mapp(me->query("quest")))
        {
                mapping quest;
                quest =  me->query("quest");
                write("�����������ܹܴ���������" + quest["quest_type"] + "��" + quest["quest"] + "����\n");
                nowtime = (int) me->query("task_time") - time();
                if( nowtime  > 0 )
                        time_period(nowtime, me);
                else
                        write("�������Ѿ�û���㹻��ʱ����������ˡ�\n");
        }else write("�޷���⵽��Ч������\n");
        return 1;
}


int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        tell_object(me,"�㻹��" + time + "ȥ�������\n");
        return 1;
}


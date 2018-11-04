// zhujia.c ���׷�
// ����lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;
int do_zhujia(string arg);

 void create()
{
        set("short", "���׷�");
        set("long", @LONG
����һ����ƽ����ͨ�����׷������ܶ������߰����ͭƤ���飬����
�Ѽ����Ŀ�ʯ����������Ժ�����ɸ��ֿ��ס�
LONG
        );

        set("exits", ([
                "west" : "/d/xiangyang/tiejiangpu",
                "east" : __DIR__"zhujian",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_zhujia","zhujia"); 
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","learn"); 
        add_action("do_quit","yun");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","fight");
        add_action("do_quit","hit");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
}

int do_zhujia(object ob)
{
        object me,ob1;
        int b1,b2;
        me=this_player();
        b1 = this_player()->query("work/zhujia");
        
        if (!(ob = present("tong kuang", this_player())) &&
             !(ob = present("tie kuang", this_player())) &&
             !(ob = present("ying kuang", this_player())) &&
             !(ob = present("jing kuang", this_player())) &&
             !(ob = present("xuantie kuang", this_player())) &&
             !(ob = present("han tie", this_player())) )
                return notify_fail("������û�п�ʯ��������ף�\n");
                 
        if ( (int)me->query("jing")<100)
                return notify_fail("��ľ������㣬�޷����ס�\n");

        if( me->is_busy() )
                return notify_fail("�����ں�æ���������ף�\n");

        if ( (int)me->query("qi")<100)
                return notify_fail("����������㣬�޷����ס�\n");

        if ( (int)me->query("neili")<150)
                return notify_fail("����������㣬�޷����ס�\n");

        message_vision(HIY"$N�Ƚ���ʯ�Ž�¯�������ɿ�״״��\n"NOR,me); 
        message_vision(HIY"����$N���ó�һ���󴸿�ʼ���ס�\n"NOR,me); 
        message_vision(HIY"��һ�����һ�ߺÿ��Ŀ��װ�����$N����ǰ��\n"NOR,me); 
        if (me->query("combat_exp")<1000000)
        {
        me->add("combat_exp",20+random(30));
        me->add("potential",15+random(15));
        }
        else 
        {
        me->add("combat_exp",6+random(20));
        me->add("potential",6+random(10));
        }
        me->add("jing",-50);
        me->add("qi",-80);
        me->add("neili",-100);
        me->start_busy(5); 

        if ( ob->query("name") ==YEL"ͭ��ʯ"NOR )
        {
        destruct(ob);             
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(YEL + this_player()->name()+"�����ͭ��"+NOR,({"tong jia","jia"}));
        b2 = ob1->query("armor_prop/armor");
        b2 = b1/10;
        if ( b2 < 10) b2 = 10;
        if ( b2 > 30) b2 = 30;
        ob1->set("armor_prop/armor", b2);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        if ( ob->query("name") ==CYN"����ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 70 ) 
        {
        me->add("work/zhujia",1);
        return notify_fail("����������֮��̫�ͣ����׸��������ã�\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(CYN + this_player()->name()+"���������"+NOR,({"tie jia","jia"}));
        b2 = ob1->query("armor_prop/armor");
        b2 = b1/8;
        if ( b2 < 20) b2 = 20;
        if ( b2 > 50) b2 = 50;
        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 5000);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        if ( ob->query("name") ==HIW"����ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 150 )
        {
        me->add("work/zhujia",1);
        return notify_fail("����������֮��̫�ͣ����׸��������ã�\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(HIW + this_player()->name()+"���������"+NOR,({"ying jia","jia"}));
        b2 = ob1->query("armor_prop/armor");
        b2 = b1/6;
        if ( b2 < 30) b2 = 30;
        if ( b2 > 80) b2 = 80;
        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 8000);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        if ( ob->query("name") ==HIY"���ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 220 )
        {
        me->add("work/zhujia",1);
        return notify_fail("����������֮��̫�ͣ����׸��������ã�\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(HIY + this_player()->name()+"����Ľ��"+NOR,({"jing jia","jia"}));
        b2 = ob1->query("armor_prop/armor");
        b2 = b1/5;
        if ( b2 < 50) b2 = 50;
        if ( b2 > 150) b2 = 150;
        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 10000);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        if ( ob->query("name") ==WHT"������ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 300 )
        {
        me->add("work/zhujia",1);
        return notify_fail("����������֮��̫�ͣ����׸��������ã�\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(WHT + this_player()->name()+"�����������"+NOR,({"xuantie jia","jia"}));
        b2 = ob1->query("armor_prop/armor");
        b2 = b1/4;
        if ( b2 < 80) b2 = 80;
        if ( b2 > 200) b2 =200;
        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 15000);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIG"������ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 400 )
        {
        me->add("work/zhujia",1);
        return notify_fail("����������֮��̫�ͣ����׸��������ã�\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(HIG + this_player()->name()+"����ĺ�����"+NOR,({"hantie jia","jia"}));
        b2 = ob1->query("armor_prop/armor");
        b2 = b1/3;
        if ( b2 < 120) b2 = 120;
        if ( b2 > 400) b2 = 400;
        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 15000);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIR"ǧ�꺮��"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/zhujia",1);
        return notify_fail("����������֮��̫�ͣ����׸��������ã�\n");
        }
        ob1=new(__DIR__"hujia/jia");
        ob1->set_name(HIR + this_player()->name()+"�����ǧ�꺮����"+NOR,({"hantie jia","jia"}));
        b2 = ob1->query("armor_prop/armor");
        b2 = b1/2;
        if ( b2 < 200) b2 = 200;
        if ( b2 > 600) b2 = 600;
        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 15000);
        ob1->move(me);
        me->add("work/zhujia", 1);       
        return 1;
        }
} 

int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ĵ����װɣ�\n");
        return 1;
}

// zhujia.c ���׷�
// ����lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;
int do_zhujia(string arg);

 void create()
{
        set("short", "��Ȫ�Ƽ�");
        set("long", @LONG
����ȫ����������Ȫ�Ƶ�Ĵ�����ȫ������ʳ�����ﶼ��
�Ե�,��������������˵Ĳ���,�����ȥ����ĳ�������
��.....
LONG
        );

        set("exits", ([
//                "east" : __DIR__"shaocai",
                "east" : __DIR__"shaocai",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_zhujia","shaocai"); 
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
        b1 = this_player()->query("work/penlen");
        
        if (!(ob = present("big cabbage", this_player())) &&
             !(ob = present("carrot", this_player())) &&
             !(ob = present("small cabbage", this_player())) &&
             !(ob = present("bai he", this_player())) &&
             !(ob = present("mao sun", this_player())) &&
             !(ob = present("ya li", this_player())) &&
             !(ob = present("tao zi", this_player())) &&
             !(ob = present("xi gua", this_player())) )
                return notify_fail("������û�в��ϣ�������ˣ�\n");
                 
        if ( (int)me->query("jing")<100)
                return notify_fail("��ľ������㣬�޷����ˡ�\n");

        if( me->is_busy() )
                return notify_fail("�����ں�æ���������ˣ�\n");

        if ( (int)me->query("qi")<100)
                return notify_fail("����������㣬�޷����ˡ�\n");

        if ( (int)me->query("neili")<150)
                return notify_fail("����������㣬�޷����ˡ�\n");

        message_vision(HIY"$N�Ƚ��߲˷Ž����г���������\n"NOR,me); 
        message_vision(HIY"����$N���ó����ֵ��Ͽ�ʼ�ղˡ�\n"NOR,me); 
        message_vision(HIY"��һ�����һ���պõ�С�˰�����$N����ǰ��\n"NOR,me); 
        message_vision(HIY"$N�ľ����Ǳ�������ˡ�\n"NOR,me); 
        me->add("combat_exp",20+random(30));
        me->add("potential",15+random(15));
        me->add("jing",-20);
        me->add("qi",-20);
        me->add("neili",-20);
        me->start_busy(5); 

        if ( ob->query("name") =="�����" )
        {
        destruct(ob);             
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(GRN + this_player()->name()+"�յĳ����"+NOR,({"cai1"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/10;
//        if ( b2 < 10) b2 = 10;
//        if ( b2 > 30) b2 = 30;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 1000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") =="���ܲ�" )
        {
        destruct(ob);             
        if ( b1 < 20 ) 
        {
        me->add("work/penlen",1);
        message_vision(HIY"��������⿼���̫�ͣ��˸������ܳԣ�\n"NOR,me); 
        return notify_fail("��������⿼���̫�ͣ��˸������ܳԣ�\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(CYN + this_player()->name()+"�յĶ������ܲ�"+NOR,({"cai2",}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/8;
//        if ( b2 < 20) b2 = 20;
//        if ( b2 > 50) b2 = 50;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 2000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") =="С�ײ�" )
        {
        destruct(ob);             
        if ( b1 < 100 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"��������⿼���̫�ͣ��˸������ܳԣ�\n"NOR,me); 
        return notify_fail("��������⿼���̫�ͣ��˸������ܳԣ�\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIW + this_player()->name()+"�յĳ��ײ�"+NOR,({"cai3"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/6;
//        if ( b2 < 30) b2 = 30;
//        if ( b2 > 80) b2 = 80;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 5000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") =="�ٺ�" )
        {
        destruct(ob);             
        if ( b1 < 220 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"��������⿼���̫�ͣ��˸������ܳԣ�\n"NOR,me); 
        return notify_fail("��������⿼���̫�ͣ��˸������ܳԣ�\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIY + this_player()->name()+"������Ҷ�ٺ�"+NOR,({"cai4",}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/5;
//        if ( b2 < 50) b2 = 50;
//        if ( b2 > 150) b2 = 150;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 8000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        if ( ob->query("name") ==GRN"ë��"NOR )
        {
        destruct(ob);             
        if ( b1 < 300 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"��������⿼���̫�ͣ��˸������ܳԣ�\n"NOR,me); 
        return notify_fail("��������⿼���̫�ͣ��˸������ܳԣ�\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(WHT + this_player()->name()+"�����Ĵ�ë��"+NOR,({"cai5",}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/4;
//        if ( b2 < 80) b2 = 80;
//        if ( b2 > 200) b2 =200;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 10000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIY"Ѽ��"NOR )
        {
        destruct(ob);             
        if ( b1 < 400 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"��������⿼���̫�ͣ��˸������ܳԣ�\n"NOR,me); 
        return notify_fail("��������⿼���̫�ͣ��˸������ܳԣ�\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIG + this_player()->name()+"����Ѽ��ƴ��"+NOR,({"cai6"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/3;
//        if ( b2 < 120) b2 = 120;
///        if ( b2 > 400) b2 = 400;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 12000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==GRN"����"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"��������⿼���̫�ͣ��˸������ܳԣ�\n"NOR,me); 
        return notify_fail("��������⿼���̫�ͣ��˸������ܳԣ�\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIR + this_player()->name()+"��������ƴ��"+NOR,({"cai7"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/2;
//        if ( b2 < 200) b2 = 200;
//        if ( b2 > 600) b2 = 600;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 15000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIM"����"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/penlen",1);
        message_vision(HIY"��������⿼���̫�ͣ��˸������ܳԣ�\n"NOR,me); 
        return notify_fail("��������⿼���̫�ͣ��˸������ܳԣ�\n");
        }
        ob1=new(__DIR__"eat/cai1");
        ob1->set_name(HIR + this_player()->name()+"��������ƴ��"+NOR,({"cai8"}));
//        b2 = ob1->query("armor_prop/armor");
//        b2 = b1/2;
//        if ( b2 < 200) b2 = 200;
//        if ( b2 > 600) b2 = 600;
//        ob1->set("armor_prop/armor", b2);
        ob1->set("value", 20000);
        ob1->move(me);
        me->add("work/penlen", 1);       
        return 1;
        }
} 

int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ĵ��ղ˰ɣ�\n");
        return 1;
}

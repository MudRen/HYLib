// blackyao.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("��ɫҩ��", ({ "black yao","yao"}) );
        if( clonep() )                       
                set_default_object(__FILE__);
        else {
                set("long","����һ���嶾�̾����Ķ�ҩ��\n" );
                set("unit", "��");
                set("value", 200);
                set("poison_type", "chanchu_poison");
                set("can_pour", 1);
                set("can_daub", 1);
                set("can_drug", 1);
                set("poison", ([
                        "level" : 250,
                        "id"    : "wudu jiao",
                        "name"  : "��ܶ�",
                        "duration": 20,
                ]));
                set("no_sell", 1);                
        }
        setup();        
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();

        if( !id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
        message_vision("$Nһ�������Ѷ�ҩȫ�����������С�\n",
                       me);
        me->set_temp("die_reason", "������ܶ�����������");
        me->die();
        destruct(this_object());
        return 1;
}

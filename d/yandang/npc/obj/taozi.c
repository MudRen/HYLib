#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("�ֺ���", ({ "taozi" }) );
        set("long", "һ��Ұ����ˮ����\n");
        set("unit", "��");
        set("weight", 100);
        set("value", 5000);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
         ob=this_player();
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");
if( living(this_player()) ==0 ) return 0;
        ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);

        write("[1;33m�����һ���ֺ��ң�ֻ���óݼ�����,��ζ���\n[0;37m");

        message("vision", HIY + ob->name() + 
"�����һ���ֺ��ң�ֻ���óݼ�����,��ζ���\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}

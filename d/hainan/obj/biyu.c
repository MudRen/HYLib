// music yangzhou's ѩ��
#include <ansi.h>

inherit ITEM;
int count=20;
void create()
{
        set_name(HIC"������Ѫ��"NOR, ({ "yu","biyu","qinglong" }) );
        set("long", "һ�����,������Ȼ�γ�һ��ѩ��ķ�����
�������(use yu)���ָ������ֵ,����ֻ��ʹ��20��.
��������,����Ը�.\n");
        set("unit", "��");
        set("weight", 100);
        set("money_id",1);
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫʹ��ʲ�᣿\n");
if( living(this_player()) ==0 ) return 0;
        ob=this_player();
        if (count==0) {
 message_vision("$N���е�$nͻȻ����һ������,��ը��.\n",ob,this_object());
 ob->die();
 destruct(this_object());
 return 1;
                 }
        ob->set("qi",(int)ob->query("max_qi"));
        ob->set("jing",(int)ob->query("max_jing"));
        ob->set("neili",(int)ob->query("max_neili"));

         ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);
        ob->set_temp("windnod",1);
        write("[1;33m�����еı��񷢳�ѩ��Ĺ�ã��\n[0;37m");
        message("vision", HIY + ob->name() + 
"���еı��񷢳�ѩ��Ĺ�,һ��������\n"+NOR,
                environment(ob), ob);
     count--;
        return 1;
}

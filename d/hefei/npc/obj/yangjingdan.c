
inherit ITEM;
#include <ansi.h>
int do_fu(string arg);
void create()
{
   set_name(GRN"������"NOR, ({ "yangjing dan","dan" }));
   set_weight(100);
   set("unit", "��");
   set("long","�����������˵�ҩ,����Է���(fu dan)����.\n");
   set("value", 2000);
   
}

void init()
{
	add_action("do_fu","fu");
}
int do_fu(string arg)
{
	object me,ob;int i;
	ob=this_object();me=this_player();
	if(!arg||(arg!="dan"&&arg!="��"))
		return notify_fail("��Ҫ����ʲô?\n");
	if(me->query("eff_jing")==me->query("max_jing"))
		return notify_fail("��ľ�û���ܵ�����,��ʲôҩ��?\n");
    i=me->query("max_jing")-me->query("eff_jing");
	if(i<=10)
	me->add("eff_jing",i);
	else me->add("eff_jing",i/5);
	message_vision("$N������һ��[������].\n",me);
	destruct(ob);
	return 1;
}
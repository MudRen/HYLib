
inherit ITEM;
#include <ansi.h>
int do_fu(string arg);
void create()
{
   set_name(HIR"��Ѫ��"NOR, ({ "buxue dan","dan" }));
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
	if(me->query("eff_qi")==me->query("max_qi"))
		return notify_fail("�����Ѫû���ܵ�����,��ʲôҩ��?\n");
    i=me->query("max_qi")-me->query("eff_qi");
	if(i<=10)
	me->add("eff_qi",i);
	else me->add("eff_qi",i/5); 
	message_vision("$N������һ��[��Ѫ��].\n",me);
	destruct(ob);
	return 1;
}
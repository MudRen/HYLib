// yfzhen.c �����
// By Kayin @ CuteRabbit Studio 1999.3.23 new
#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_yong","shoot");
}

void create()
{
	set_name(HIY"�����"NOR, ({ "yufeng zhen", "zhen" }) );
    	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "ö");
	set("value", 1000);
	set("material", "gold");
        set("long", "����һö�þ������Իƽ����ɵ�ϸ�緢˿�Ľ���  ���������(shoot).\n");
        	}
	setup();
}
int do_yong(string arg)
{
	object me,target;
	mapping myfam;
	me=this_player();
if(!me->query("family"))
return notify_fail("�����Լ����������������?\n");
	myfam = (mapping)me->query("family");
   if(!arg)
       return notify_fail("��Ҫ���������˭��\n");
	
	if( !me->is_fighting() )
		return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((!myfam || myfam["family_name"] != "��Ĺ��"))
		return notify_fail("�����Լ����������������?\n");
		

        if ( (int)me->query_skill("throwing",1) <= 0 )
        return notify_fail("����ð����𣿣�\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(target == me)
        return notify_fail("������ɱ�� :p\n");
        
    message_vision(HIY "\n$N�ӻ�������һö"HIY"�����"HIY"�������У����������һöϸ�緢˿�Ľ�������$n,\n"NOR,me,target);
    me-> start_busy (2) ;
    if (  random ( (int)me->query_skill("throwing")*2 ) < (int)target->query_skill("dodge") / 2 )
      {
      message_vision(HIB"\n��$n"HIB"��ӳ���٣��о����յĶ㿪��$N��"HIY"����룡\n"NOR , me, target);
      }
    else
      {
       message_vision( HIR "\nֻ��"HIC"$n"HIR"����һ�ӣ�һö��������"HIC"$N"HIR"�����ڡ�\n"NOR,target ,me);
	target->apply_condition("yufeng_poison",(int)target->query_condition("yufeng_poison")+ 10);
      }
         destruct(this_object());
    return 1;
}
	
		
// yfzhen.c ������
// By Kayin @ CuteRabbit Studio 1999.3.23 new
#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void init()
{
        add_action("do_yong","shoot");
}

void create()
{
   set_name(HIG"������"NOR, ({"bilin zhen", "zhen", "bilin"}));
    	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "Щ");
                set("value", 0);
                set("base_unit", "ö");
                set("base_weight", 300);
                set("base_value", 0);
	set("value", 0);
                set("material", "iron");
      set("long", HIG"һö���������͹�ã��ϸ�룬һ����֪ι�о綾�������
      ��(shoot)\n" NOR);
        	}
        set_amount(50);
        init_throwing(50);
	setup();
}
int do_yong(string arg)
{
	object me,target;
	mapping myfam;
string limbs;
	me=this_player();
if(!me->query("family"))
return notify_fail("�����Լ�������������?\n");
	myfam = (mapping)me->query("family");
   if(!arg)
       return notify_fail("��Ҫ������˭��\n");

   if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������"))
                  return notify_fail("ֻ�����޵������ñ����ش��ڹ�����ʹ�ñ����롣\n"); 


	if( !me->is_fighting() )
		return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ( (int)me->query_skill("poison",1) <= 0 )
        return notify_fail("����ö�����\n");

	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");
	if(target == me)
        return notify_fail("������ɱ�� :p\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������,ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
   message_vision(HIG"$N�������������һ�һ����̵����⣬��$n�����ȥ��\n" NOR, me, target);
    me-> start_busy (2) ;
    if (  random ( (int)me->query("combat_exp")+(int)me->query_skill("poison",1)*500 ) < (int)target->query("combat_exp") / 2 )
      {
      message_vision(HIB"\n��$n"HIB"��ӳ���٣��о����յĶ㿪��$N��"HIY"����룡\n"NOR , me, target);
      }
    else
      {
   limbs = target->query("limbs");
if (limbs)
{
   message_vision(CYN"\n���$Nһ���ҽУ���������Ȼ������$N��"+limbs[random(sizeof(limbs))]+"��\n"NOR, target, me);
}
	target->apply_condition("insect_poison",(int)target->query_condition("insect_poison")+ 40);
      }
         destruct(this_object());
    return 1;
}
	
	
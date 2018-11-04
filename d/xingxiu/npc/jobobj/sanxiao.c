//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int throw_ob(string arg);
void create()
{
   set_name(BLU"��ң��Цɢ"NOR, ({"sanxiao san", "san", "sanxiao", "zhuihun"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("long", HIG"һ�����Ե�(tanshe)�Ķ�ҩ��\n" NOR);
      set("unit", "��");
      set("value", 0);
		set("pour_type", "sanxiao_poison");
   }
   setup();
}

void init()
{
        object me = this_player();
        add_action("throw_ob","tanshe"); 
	add_action("do_eat", "eat");

}


int throw_ob(string arg)
{
   int skill, skill2, thr, dod, poi, my_neili, u_neili, myexp, urexp, par;
   mapping myfam, vfam;
   object me,victim;   

me=this_player();
   if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������"))
                  return notify_fail("ֻ�����޵������ñ����ش��ڹ�����ʹ����Цɢ��\n"); 

        if( !arg ) return notify_fail("�����˭ʹ����Цɢ��\n");

        if( !objectp(victim = present(arg, environment(me))) )
                return notify_fail("����û������ˡ�\n");

        if( victim->query("id")==me->query("id"))
                return notify_fail("����ɱ�Լ���\n");


   if( me->query("neili") <= 2000 ){
        write("�����������������ң��Цɢ����\n");
        return 1;
   }

   if (me->query_skill("poison", 1) < 100){
        write("���Ķ������Լ���\n");
        return 1;
   }

   if( environment(me)->query("no_fight") ) return notify_fail("����!\n");
	
   if( me->is_busy() ) return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");
	if( !victim
	||	!victim->is_character()
	||	!me->is_fighting(victim) )
		return notify_fail("��Ц׷��ɢ,ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	

   if (victim->query_condition("sanxiao_poison")){  
        write("������������Ц׷��ɢ���������ӣ�\n");
        return 1;
   }

   if (me->query_condition("killer") > 10 && userp(victim)){
        write("��е�һ˿�ھΣ���ͻȻ����������\n");
        return 1;
   }
   
   tell_object(me, BLU"������һ��ָ������ң��Цɢ��"+victim->query("name")+"���ϵ�ȥ��\n"NOR);
   	

   if (me->query_skill("poison", 1) < 100){
           this_object()->set_temp("used", 1);
           me->apply_condition("sanxiao_poison",4); 
           tell_object(me, "�㶾���û����������Լ��ˣ�\n");
           destruct(this_object());
        return 1;
   }

   if (me->query_skill("poison", 1) < victim->query_skill("poison", 1) + 30){
           victim->apply_condition("insect_poison", 100);
           return 1;
   }

   thr = me->query_skill("feixing-shu", 1);
   poi = me->query_skill("poison",1);
   dod = (int)victim->query_skill("force",1);
   par = (int)victim->query_skill("parry",1);
   
   my_neili = me->query("neili")/3*2;
   u_neili = (int)victim->query("neili")/3*2;
   
   skill = thr + poi + my_neili;
   skill2 = dod + par + u_neili;
   skill += me->query("combat_exp")/10000;
   skill2 += victim->query("combat_exp")/10000;
   me->add("neili", -150);

   myexp=me->query("combat_exp");
   urexp=victim->query("combat_exp"); 

   if (wizardp(me))
   	printf("my skill=%d  ur skill=%d\n",skill, skill2);

   if ( skill > skill2+random(skill2/2) ){

        if (urexp>=myexp ) 
               me->improve_skill("feixing-shu", 100);
        
        if(userp(victim) && urexp>=myexp ){
                me->add("combat_exp", 20);
        }
        
   	message_vision(HIR"$nһ��С�ı�$N��������Ц׷��ɢ����������!\n"NOR, me, victim);                
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        victim->start_busy(3);
        victim->apply_condition("sanxiao_poison",6);      
        destruct(this_object());
        return 1;
   } else if (skill>skill2){
   	message_vision(HIY"$nͻȻ����һ�����Ϯ����æ���һԾ�����˿�ȥ��\n"NOR, me, victim);
   	this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        me->start_busy(random(3)+1);
   } else {
        message_vision(HIR"$n����һ����һ���ھ�������������Цɢ������$N������ȥ��\n" NOR, me, victim);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        me->apply_condition("sanxiao_poison",4);
        me->start_busy(random(3)+1);
  }
  
  destruct(this_object());
  return 1;
}    

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if(arg=="san" || arg=="xiaoyao san")
	{
		message_vision("$N��ͷ����һ��" + name() + "��\n", me);
		this_player()->die();
		destruct(this_object());
	}
	return 1;
}

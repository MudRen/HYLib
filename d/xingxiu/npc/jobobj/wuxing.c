//Cracked by Roath
#include <ansi.h>

inherit ITEM;
int throw_ob(string arg);
void create()
{
   set_name(HIW"����ɢ"NOR, ({"wuxing san", "san", "wuxing"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("long", HIG"һ�����Ե�(tanshe)�Ķ�ҩ��\n" NOR);
      set("unit", "��");
      set("value", 0);
      set("skill", "feixing-shu");
   }
   setup();
}
void init()
{
        object me = this_player();
        add_action("throw_ob","tanshe"); 
}
int throw_ob(string arg)
{
   int skill, skill2, thr, dod, poi, my_neili, u_neili, myexp, urexp, par;
   mapping myfam, vfam;
   object me,victim;   

me=this_player();
   if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������"))
                  return notify_fail("ֻ�����޵������ñ����ش��ڹ�����ʹ������ɢ����\n"); 

        if( !arg ) return notify_fail("�����˭ʹ������ɢ����\n");

        if( !objectp(victim = present(arg, environment(me))) )
                return notify_fail("����û������ˡ�\n");

        if( victim->query("id")==me->query("id"))
                return notify_fail("����ɱ�Լ���\n");
	if( !victim
	||	!victim->is_character()
	||	!me->is_fighting(victim) )
		return notify_fail("����ɢ��,ֻ�ܶ�ս���еĶ���ʹ�á�\n");

   if( me->query("neili") <= 1000 ){
        write("�������������������ɢ����\n");
        return 1;
   }

   if (me->query_skill("poison", 1) < 120){
        write("���Ķ������Լ���\n");
        return 1;
   }

   if( environment(me)->query("no_fight") ) return notify_fail("����!\n");
	
   if( me->is_busy() ) return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");
	


   if (me->query_condition("killer") > 10 && userp(victim)){
        write("��е�һ˿�ھΣ���ͻȻ����������\n");
        return 1;
   }
   
   message_vision(HIW"$N΢΢һЦ�����Сָ��$n����һ����$n������ǰһ�����ƺ���һ��������Լ�Ʈ����\n"NOR, me, victim);

   if (me->query_skill("poison", 1) < victim->query_skill("poison", 1) + 30){
           victim->apply_condition("insect_poison", 100);
           return 1;
   }

   thr = me->query_skill("feixing-shu", 1);
   poi = me->query_skill("poison",1);
   dod = (int)victim->query_skill("force",1);
      
   my_neili = me->query("neili");
   u_neili = (int)victim->query("neili");
   
   skill = thr + poi + my_neili;
   skill2 = dod + u_neili;
   skill += me->query("combat_exp")/1000;
   skill2 += victim->query("combat_exp")/1000;
   me->add("neili", -150);

   myexp=me->query("combat_exp");
   urexp=victim->query("combat_exp");

   if ( skill > skill2){

        if (urexp>=myexp/2) 
                me->improve_skill("feixing-shu", 100);
        
        
        
                
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        message_vision(HIR"$nһ��С�ı�$N����������ɢɢ����������!\n" NOR, me, victim);
        victim->apply_condition("sanpoison",me->query_skill("poison",1));      
        destruct(this_object());
      
  	me->start_busy(2);
  	victim->start_busy(2);
        
        return 1;
   } else {
        message_vision(HIR"$n����һ����һ���ھ���������������ɢ������$N������ȥ��\n" NOR, me, victim);
        this_object()->set_temp("used", 1);
        this_object()->set("value", 10);
        victim->apply_condition("sanpoison",me->query_skill("poison",1));      
  }
  
  me->start_busy(2);
  victim->start_busy(2);
  
  destruct(this_object());
  return 1;
}    

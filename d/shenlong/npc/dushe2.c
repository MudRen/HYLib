inherit NPC;

void kuser();

void create()
{
    set_name("����", ({ "dushe", "snake", "she" }) );
    set("race", "Ұ��");
    set("age", 20);
    set("long", "һ�����м�ڵĶ��ߣ�ȫ��Ѫ�졢�������¡�����������ͷ������\n");
    set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 20000);
	
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 100);
	call_out("kuser",5);
	setup();
}

void kuser()
{
      object *ob,me;
      int i;
      
      me=this_object();
        if(!environment(me))  return;
      ob = all_inventory(environment(me));
      for(i=0;i<sizeof(ob);i++)
      {
          if(userp(ob[i]))
	  {
          	me->kill_ob(ob[i]);
		ob[i]->kill_ob(me);
	  } 
      }
      call_out("kuser",5);
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 8);
        return 0;
}

 

// migong lev1

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name("Ұ��", ({ "wolf", "lang" }));
      
          set("race", "Ұ��");
       set("long",
"һֻ���е�Ұ�ǣ������ŵĴ�����¶�ż����������\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
	       set("max_qi",500+random(500));
  set("max_jing",500+random(500));
  set("max_sen",500+random(500));
  set("max_mana",500+random(500));
  
      set("dex",30);
     set("str" ,25);
       
    set("age", 5);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 300000);
                  
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/defence",50);

   setup();

        

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;           
              me->add("score",1);
        message_vision(WHT"$Nһ���ҽ�,���ڵ��ϣ����˸���ͷ�Ͳ������ˡ�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 200000)   {
        message("vision", me->name() + "�ɹ���������������40�����20Ǳ�ܡ�\n", me);
        me->add("combat_exp",40);
        me->add("potential",20);
        destruct(ob);
        }
               destruct(ob);
        return;
}
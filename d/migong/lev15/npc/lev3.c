// migong lev15

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(MAG"����"NOR, ({ "du long" , "long" , "dragon" }));
                set("race", "Ұ��");
       set("long",
"һ�������ϣ���ª�����ľ������������㣬�������˹�����
��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",15000+random(10000));
  set("max_jing",15000+random(10000));
  set("max_sen",20000+random(10000));
  set("max_mana",20000+random(10000));
  
      set("dex",50);
      set("con",50);
     set("str" ,50);
       
    set("age", 80);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 9000000+random(2000000));
            set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",100);
      set_skill("dodge", 400+random(100));

      set_skill("unarmed", 700+random(100));

       set_skill("dragon", 500+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
     
   setup();

    
carry_object("/d/migong/obj/longdan");
     

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") )
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
        message_vision(WHT"$Nһ��ŭ�𣬻�����Ѫֱ���������ɵ��ڵء�\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 26000000)   {
        message("vision", me->name() + "�ɹ���������������400�����150Ǳ�ܡ�\n", me);
        me->add("combat_exp",400);
        me->add("potential",150);
        destruct(ob);
        }
               destruct(ob);
        return;
}




int hit_ob(object me, object ob, int damage)
{

        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n" NOR );
}

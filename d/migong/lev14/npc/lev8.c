// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(MAG"毒龙"NOR, ({ "du long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条浑身发紫，丑陋不堪的巨龙，看到了你，向你扑了过来。
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",20000+random(10000));
  set("max_jing",20000+random(10000));
  set("max_sen",20000+random(10000));
  set("max_mana",20000+random(10000));
  
      set("dex",60);
      set("con",60);
     set("str" ,60);
       
    set("age", 80);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 8000000+random(2000000));
            set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/defence",200);
      set_skill("dodge", 400+random(100));

      set_skill("unarmed", 700+random(100));

       set_skill("dragon", 500+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
     set("chat_chance", 30);
        set("chat_msg", ({
		(: command("get silver") :),
		(: command("get gold") :),
		(: command("get coin") :),
                (: random_move :),
           }) );     
   setup();

    
carry_object("/d/migong/obj/longdan");
     

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
        message_vision(WHT"$N一声怒吼，浑身鲜血直流，缓缓躺倒在地。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 15000000)   {
        message("vision", me->name() + "成功打死猎物增加了400经验和150潜能。\n", me);
        me->add("combat_exp",400);
        me->add("potential",150);
        destruct(ob);
        }
               destruct(ob);
        return;
}




int hit_ob(object me, object ob, int damage)
{
   if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("wugong_poison") < 10 ) {
		ob->apply_condition("wugong_poison", 40);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
	}
}

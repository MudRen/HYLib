#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"ʳ��ħ��ʦ"NOR, ({ "ogre magi"}));
	set("magicgift",2);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"һֻ���µ�ʳ��ħ��ʦ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",20000000+random(8000000));
        set_skill("force",400+random(200));
	set_skill("unarmed",400+random(200));
	set_skill("sword",400+random(200));
	set_skill("club",400+random(200));
	set_skill("whip",400+random(200));
	set_skill("throwing",400+random(200));
	set_skill("parry",400+random(200));
      set_skill("spells",300+random(200));
      set_skill("magic-unarmed", 400+random(200));
      set_skill("magic-sword", 400+random(200));
      set_skill("magic-fire", 400+random(200));
      set_skill("magic-water", 400+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-water");
        set("no_get",1);
b=13500+random(4500);
a=11111+random(4500);
d=30+random(60);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);

        set("neili",a);
        set("max_neili",a);
       
    set("age", 15);

        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);

 set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
    (: perform_action, "spells.iceball" :),
 (: perform_action, "spells.crystal" :),
 }) );

   setup();

//carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
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
        message_vision(RED"$N,���ض������������ˡ�\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"�ɹ�����"+ob->query("name")+",������100�����50Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",100);
        me->add("potential",50);
              me->add("score",1);
        destruct(ob);
        }
 
               destruct(ob);
        return;
}

int hit_ob(object me, object ob, int damage)
{
string msg;
        if(random((int)me->query("combat_exp")) > ob->query("combat_exp")/2)   
{
if (!ob->is_busy())
             ob->start_busy(1);
           msg = HIW"$N"HIW"ͻȻ����$n"HIW"����!!���$n"HIW"���ж�����Ӱ����!\n"NOR;
            message_vision(msg, me, ob);
}
}
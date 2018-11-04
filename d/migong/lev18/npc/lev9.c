#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"�ƽ���"NOR, ({ "gold dragon"}));
	set("magicgift",4);
	set("magicset",1);
       set("zhuanbest",1);
       set("long",
"һֻ���µĹ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",40000000+random(8000000));
        set_skill("spells",400+random(300));
        set_skill("force",450+random(300));
	set_skill("unarmed",450+random(300));
	set_skill("sword",450+random(300));
	set_skill("club",450+random(300));
	set_skill("whip",450+random(300));
	set_skill("throwing",450+random(300));
	set_skill("parry",450+random(300));
      set_skill("magic-unarmed", 450+random(300));
      set_skill("magic-sword", 450+random(300));
      set_skill("magic-earth", 450+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-earth");
        set("no_get",1);
	set_skill("force",450+random(300));
	set_skill("force",450+random(300));
	set_skill("huntian-qigong",450+random(300));
	map_skill("force", "huntian-qigong");	
b=11000+random(6000);
a=14000+random(8000);
d=30+random(60);
set("str",d);
set("dex",80+d);
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

 set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
    (: perform_action, "spells.Attach" :),
    (: perform_action, "spells.missile" :),
    (: perform_action, "spells.quake" :),
 }) );
if (random(8)==0)
{
set("nickname",HIY"�书�߳�"NOR);
        set_skill("spells",650+random(300));
        set_skill("force",650+random(300));
	set_skill("unarmed",650+random(300));
	set_skill("sword",650+random(300));
	set_skill("club",650+random(300));
	set_skill("whip",650+random(300));
	set_skill("throwing",650+random(300));
	set_skill("parry",650+random(300));
}
else
if (random(8)==0)
{
set("nickname",MAG"ħ��ǿ��"NOR);
      set_skill("magic-unarmed", 650+random(300));
      set_skill("magic-sword", 650+random(300));
      set_skill("magic-ice", 650+random(200));
      set_skill("magic-water", 650+random(200));
      set_skill("magic-fire", 650+random(200));
      set_skill("magic-earth", 650+random(200));
      set_skill("magic-light", 650+random(200));
      set_skill("magic-dark", 650+random(200));
}
else
if (random(8)==0)
{
set("nickname",HIB"����ḻ"NOR);
set("combat_exp",50000000+random(48000000));
}
else
if (random(8)==0)
{
set("nickname",HIR"ǿ����"NOR);
set("dex",300);
        set("jing",600000);
        set("max_jing",600000);
        set("eff_jing",600000);
        set("qi",600000);
        set("max_qi",600000);
        set("eff_qi",600000);
        set("neili",600000);
        set("max_neili",600000);
	set("combat_exp",10000000);
}
else
if (random(8)==0)
{
set("nickname",HIC"������ǿ"NOR);
d=88+random(88);
set("str",d);
set("dex",80+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}

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
        message("vision", me->name() + HIG"�ɹ�����"+ob->query("name")+",������200�����100Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",200);
        me->add("potential",100);
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
             ob->add("qi",-ob->query("qi")/30);
             ob->add("eff_qi",-ob->query("eff_qi")/30);
             ob->add("jing",-ob->query("jing")/30);
             ob->add("eff_jing",-ob->query("eff_jing")/30);
         ob->apply_condition("ice_poison", 40);
        ob->apply_condition("xx_poison", 40);
        ob->apply_condition("cold_poison", 40);
        ob->apply_condition("flower_poison", 40);
if (random(4)==0)
ob->apply_condition("sanxiao_poison", 2);
           msg = HIR"$N"HIR"���¶���"HIR"$n"HIR"�������Χ��!!\n"NOR;
            message_vision(msg, me, ob);
}
}
#include <ansi.h>
inherit NPC;
mapping *data=({
(["id":"devil corps","title":"ħ�����","name":"����ħ��ʿ",]),
(["id":"devil corps","title":"ħ�����","name":"�߼�ħ��ʿ",]),
(["id":"devil corps","title":"ħ�����","name":"��ϰħ��ʹ",]),
(["id":"devil corps","title":"ħ�����","name":"�ȷ�ħ��ʹ",]),
(["id":"devil corps","title":"ħ�����","name":"ħ��ʹָ�ӹ�",]),
(["id":"devil corps","title":"ħ�����","name":"��ħ�峤",]),
(["id":"devil corps","title":"ħ�����","name":"��ħ��ʦ",]),
(["id":"devil corps","title":"ħ�����","name":"���鷨ʦ",]),
(["id":"devil corps","title":"ħ�����","name":"��ħ�峤",]),
(["id":"devil corps","title":"ħ�����","name":"ħ�ų�",]),
(["id":"devil corps","title":"ħ�����","name":"��ħ�ų�",]),
(["id":"devil corps","title":"ħ�����","name":"ħ��˾��Ŀ",]),
(["id":"devil corps","title":"ħ�����","name":"ħ�����ͳ��",]),
(["id":"devil corps","title":"ħ�����","name":"ħ������",]),
(["id":"devil corps","title":"ħ�����","name":"ħ����",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
set_name(order[random(13)]+npc["name"]+NOR,({ npc["id"] }));    
set("nickname",(HIB+npc["title"])+NOR);
	set("magicgift",1+random(6));
	set("zhuanbest",1);
	set("magicset",1);
       set("long",
"һλħ����ŵ�սʿ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",45000000+random(8000000));
        set_skill("force",490+random(300));
	set_skill("unarmed",490+random(300));
	set_skill("sword",490+random(300));
	set_skill("club",490+random(300));
	set_skill("whip",490+random(300));
	set_skill("throwing",490+random(300));
	set_skill("parry",490+random(300));
      set_skill("magic-dark", 490+random(300));
      set_skill("magic-light", 490+random(300));
      set_skill("magic-earth", 490+random(300));
      set_skill("magic-ice", 490+random(300));
      set_skill("magic-water", 490+random(300));
      set_skill("magic-fire", 490+random(300));
      set_skill("magic-unarmed", 490+random(300));
      set_skill("magic-sword", 490+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
        set("no_get",1);
      set_skill("magic-dark", 700+random(300));
      set_skill("magic-light", 700+random(300));
      set_skill("magic-earth", 600+random(300));
      set_skill("magic-ice", 600+random(300));
      set_skill("magic-water", 600+random(300));
      set_skill("magic-fire", 600+random(300));
      set_skill("magic-unarmed", 600+random(300));
      set_skill("magic-sword", 600+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
	set_skill("force",650+random(300));
	set_skill("huntian-qigong",650+random(300));
	map_skill("force", "huntian-qigong");
b=25600+random(6000);
a=27600+random(5000);
d=95+random(60);
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

set("shen",-100000);
        set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
     set("chat_chance", 3);
        set("chat_msg", ({
                (: random_move :),
           }) );
if (random(2)==0)
{
     map_skill("spells", "magic-dark");
        set("chat_chance_combat", 69);
        set("chat_msg_combat", ({
              (: perform_action, "spells.nuclea" :),
               (: perform_action, "spells.darkstorm" :),
               (: perform_action, "spells.darkwind" :),
               (: perform_action, "spells.darkmetor" :),
               (: perform_action, "spells.darkforce" :),
               (: perform_action, "spells.dragon" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.castigate" :),                                                              
        }) );
}
else 
{
     map_skill("spells", "magic-earth");
        set("chat_chance_combat", 69);
        set("chat_msg_combat", ({
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.stab" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.Attach" :),
               (: perform_action, "spells.missile" :),
               (: perform_action, "spells.quake" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.Dintfield" :),                                                             
        }) );
        }
   setup();

carry_object(__DIR__"obj/sword")->wield();
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
        message_vision(RED"$N,���ض������������ˡ�\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"�ɹ�����"+ob->query("name")+",������80�����40Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",80);
        me->add("potential",40);
        destruct(ob);
        }

               destruct(ob);
        return;
}


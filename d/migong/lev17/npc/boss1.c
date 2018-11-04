#include <ansi.h>
inherit NPC;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIB"", ""HIW"", ""HIB"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


void create()

{
	mapping npc,mp,j;
	int i,k,a,b,c,d,e,f,temp;
   set_name(order[random(13)]+"������"NOR, ({ "lakshi"}));
if (random(2)==0)
	set("magicgift",1);
else 	set("magicgift",2);
	set("magicset",1);
       set("title",HIB"ˮ֮����ʹ"NOR);
       set("zhuanbest",1);
       set("long",
"һλ���µ�ˮ֮����ʹ��\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);
	       set("max_qi",500+random(500));
	set("combat_exp",29000000+random(8000000));
        set_skill("force",400+random(300));
	set_skill("unarmed",400+random(300));
	set_skill("sword",400+random(300));
	set_skill("club",400+random(300));
	set_skill("whip",400+random(300));
	set_skill("throwing",400+random(300));
	set_skill("parry",400+random(300));
      set_skill("magic-unarmed", 400+random(200));
      set_skill("magic-sword", 400+random(200));
      set_skill("magic-fire", 600+random(200));
      set_skill("magic-water", 600+random(200));
      set_skill("magic-ice", 600+random(200));
set_skill("spells",600+random(200));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
map_skill("spells", "magic-water");
        set("no_get",1);
b=168000+random(68000);
a=188000+random(69000);
d=38+random(60);
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
	set_temp("apply/armor",600);
	set_temp("apply/damage",600);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.zeroring" :),                                                            
        }) );
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
        object jla , jlb;        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
              me->add("score",1);
        message_vision(HIB"$N,���ض�������Ϊ��һ̲ˮ��\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"�ɹ�����"+ob->query("title")+HIG",���������\n"NOR, users());
        me->add("combat_exp",600);
        me->add("potential",300);
        me->add("score",1);
if (!present("water jian", me)
&& me->query("zhuanbest")
)
{
        jla=new("/clone/magic/obj/sword12");
        jla->move(me);
message("vision", me->name() + HIG"�ҵ��˹Ŵ�����:"+jla->query("name")+HIG"��\n"NOR, users());
}
        destruct(ob);
        }
if (!present("water jian", me)
&& me->query("zhuanbest")
)
{
        jla=new("/clone/magic/obj/sword12");
        jla->move(me);
message("vision", me->name() + HIG"�ҵ��˹Ŵ�����:"+jla->query("name")+HIG"��\n"NOR, users());
}

               destruct(ob);
        return;
}


void unconcious()
{
die();
}

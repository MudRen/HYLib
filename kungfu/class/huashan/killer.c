#include <ansi.h>
inherit NPC;

string *nm1_jp =({
"����"
});

    
string *nm2_jp =({
"��",
});

void create()
{
string weapon;
       object me;
        int myskill;
   int i = random(sizeof(nm1_jp));
        me=this_player();
    set_name(HIB "������" NOR, ({ me->query("id")+"-mengmian"}));

    set("gender", "����" );//�Ա��������Ӧ

	set("long",
		"��һ�ڽ����棬˫������ɱ����ʱ��ʱ�ͳ�����Ц��\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
  set("max_qi",500+random(1890));
  set("max_jing",500+random(1890));
  set("max_sen",500+random(1890));
  set("max_neili",500+random(1890));
  set("max_mana",500+random(1890));
  set("eff_neili",500+random(2000));
  set("neili",500+random(2000));
        set("per", random(26)+10);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(900000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.diansha" :),
                (: perform_action, "sword.tmbiao" :),
                (: perform_action, "sword.tmbiao" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "blade.moxiao" :),
                (: perform_action, "unarmed.huashen" :),                
                (: perform_action, "unarmed.tmduan" :),                
        }) );

        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        



         set_skill("tmzhang", 150+random(180));
        set_skill("staff", 150+random(180));
        set_skill("tmjian", 150+random(180));
        set_skill("tmdao", 150+random(180));
        set_skill("pmshenfa", 150+random(180));
        set_skill("strike",150+random(180));
        set_skill("blade", 150+random(180));
        set_skill("sword", 150+random(180));
        set_skill("xue-dao", 150+random(180));
        set_skill("unarmed",150+random(180));
        set_skill("xianglong-zhang",150+random(180));
        set_skill("dodge", 150+random(180));
        set_skill("blade", 150+random(180));
        set_skill("parry", 150+random(180));
        set_skill("dashou-yin", 150+random(180));
        set_skill("shenkong-xing", 150+random(180));
        set_skill("longxiang", 150+random(180));
        set_skill("huntian-qigong", 150+random(180));
        set_skill("tmdafa", 150+random(180));
        set_skill("whip", 150+random(180));
        set_skill("chilian-shenzhang", 150+random(180));
        set_skill("jueqing-bian", 150+random(180));
        map_skill("unarmed", "tmzhang");
        map_skill("sword", "tmjian");
        map_skill("parry", "tmjian");
        map_skill("blade", "tmdao");
        map_skill("dodge", "pmshenfa");
        map_skill("force", "tmdafa");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 100);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}
       create_family("�������",3,"����");	
        weapon = random(2)?"/clone/weapon/gangdao":"/clone/weapon/changjian";
        setup();

        carry_object("clone/misc/cloth")->wear();
        carry_object(weapon)->wield();

}
void init( )
{
        call_out("hunting",300);
}

void hunting()
{
object ob=this_object();
if (!ob) return;
command("say �����Ѿ��鿴���ˣ����������������!");
destruct(ob);
}


void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (!me) return;
        message_vision(WHT"$N�ҽ�һ�������ض�������\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if(me->query("family/family_name") == "��ɽ��" 
        && this_object()->query_temp("owner/id") == me->query("id")        )   {
        message("vision", me->name() + HIC"���ڳɹ���������ħ��̽��,������230�����130Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",230);
        me->add("potential",130);
        }

        destruct(ob);
        return;
}

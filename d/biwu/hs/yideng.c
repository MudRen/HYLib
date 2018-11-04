// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("һ�ƴ�ʦ", ({"yideng dashi", "dashi", "yideng"}));
    set("title", HIC "�ϵ�" NOR );
    set("gender", "����");
    set("age", 52);
    set("long", 
        "�����Ǻųơ��ϵۡ���һ�ƴ�ʦ�����������ˣ�����ѷλΪɮ��\n"
        "��ʦһ�����ƣ��������\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 60);
    set("int", 60);
    set("con", 66);
    set("dex", 60);
        set_temp("no_kill",1);
    set("qi", 19000);
    set("max_qi", 19000);
    set("jing", 19000);
    set("max_jing", 19000);
    set("neili", 50500);
    set("max_neili", 50500);
        set("jiali", 100);
        set("szj/passed",1);
//        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
         set_temp("apply/attack", 50);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 80);
	
    set("combat_exp", 5500000);
    set("score", 0);
	 
        set_skill("unarmed", 400);
        set_skill("force", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("cuff", 400);
        set_skill("strike", 500);
        set_skill("sword", 500);
        set_skill("staff", 500);
        set_skill("finger", 400);
        set_skill("buddhism", 500);
	set_skill("kurong-changong", 500);
        set_skill("tiannan-step", 500);
        set_skill("jinyu-quan", 500);
        set_skill("wuluo-zhang", 500);
        set_skill("duanjia-sword", 500);
        set_skill("yiyang-zhi", 500);
        set_skill("six-finger", 350);
        set_skill("sun-finger", 500);
	set_skill("literate", 500);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	map_skill("unarmed", "six-finger");
	map_skill("finger", "yiyang-zhi");
	map_skill("parry", "yiyang-zhi");

//	prepare_skill("cuff", "jinyu-quan");
//	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "unarmed.liumaijingshen" :),
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );

    setup();

    carry_object("/clone/misc/cloth")->wear();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",HIG"���������\n\n"
		+ name() + HIG"����һ������ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void unconcious()
{
die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;
if (me==ob){
me->set("qi",1);
me->set("eff_qi",1);
me->set("jing",1);
me->set("eff_jing",1);
}

if (!me->query_skill("jiuyin-zhengong",1)
&& me->query_temp("hsljn"))
{
me->set_temp("hslj/3",1);
message("channel:chat", "����ɽ�۽�����˵"+me->name() + "�����"+ob->query("title")+ob->query("name")+"!"NOR"\n", users());
        me->add("combat_exp",300);
        me->add("potential",100);
}
        destruct(ob);
        return;
}
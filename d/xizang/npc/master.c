 inherit NPC;
inherit F_MASTER;
#include <ansi.h> 

int leave(); 
void create()
{
        set_name("ɣ��", ({ "sang jie", "master","sangjie" }) );
        set("gender", "����" );
        set("class","lama");
        set("age", 99);
        set("int", 30);
        set("agi",25);
        set("int",30);
        set("fle",50);
        set("apprentice_available", 20);
        create_family("������", 20, "����");
    set("rank_nogen",1);
    set("ranks",({"����","�޺�","��ɮ","��ʦ","ʥɮ",YEL"����"NOR,YEL"���"NOR,HIY"����"NOR}));
        set("long",
                "ɣ���ɮ���ڴ��������ֶ��ꡣ��Ů���ӱ鲼���⡣\n"
                );
        set("inquiry", ([
                "������": "��....������.....���������\n",
                "����": "�����ڴ����µ�ľ���",
                "leave": (: leave:),
        ]) );
        set("combat_exp", 3000000+random(1500000));
        set("score", random(90000));
        set("reward_npc", 1);
        set("difficulty", 30);
        set("mana",4000);
        set("max_mana",4000); 
        set("max_neili",1500);
        set("neili",1500);
        set("neili",16000);
        set("max_neili",16000);

        set("force_factor",30); 
        set_skill("unarmed", 200);
        set_skill("dodge", 100);
		set_skill("move", 100);
        set_skill("staff", 200);
        set_skill("force", 180);
        set_skill("parry", 150);
        set_skill("literate", 140);
        set_skill("iron-cloth", 230);
        set_skill("bloodystrike", 150);
        set_skill("lamaism", 200);
        set_skill("jin-gang", 200);
        set_skill("spells",200);

        
        
        map_skill("unarmed", "bloodystrike");
        map_skill("iron-cloth", "jin-gang");
        
        set_temp("apply/iron-cloth",200); 
/*      set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
                (: perform_action, "unarmed.fefawubian" :),
                (: cast_spell, "an" :),
        }) ); */
        
	set_skill("iron-cloth", 150);

	set_skill("bloodystrike", 300);
	set_skill("cloudstaff", 300);
	set_skill("bolomiduo", 300);
	set_skill("buddhism", 300);
        set_skill("jin-gang", 350);


	map_skill("unarmed", "bloodystrike");
        map_skill("force", "bolomiduo");
        map_skill("literate", "buddhism");
        map_skill("iron-cloth", "jin-gang");
        map_skill("staff", "cloudstaff");
        map_skill("parry", "cloudstaff");        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.siqijinlong" :),
                (: perform_action, "staff.longxianyuye" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);                
        setup();
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/9staff")->wield();
}  

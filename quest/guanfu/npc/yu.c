// yu ������
 
inherit NPC;
 
void create()
{
	set_name("������", ({ "yu zhenzi", "yu" }));
//	set("nickname", "�˱���");
	set("long", 
        "�����ŵ���ͽ�������ɫ���������ְ��࣬����һ������ͳ����뻯��\n");
	set("gender", "����");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen", -18000);
	set("str", 35);
	set("int", 30);
	set("con", 25);
	set("dex", 27);
	set("per",10);
           set("eff_jingli",2000);
	set("max_qi", 5500);
	set("max_jing", 5500);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 150);
       set("combat_exp", 1200000+random(900000));
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
   		(: perform_action, "sword.sanqing" :),
		(: perform_action, "sword.tonggui" :),
        }));

        set_skill("force", 130);
        set_skill("xiantian-qigong", 330);    //��������
        set_skill("sword", 130);
        set_skill("quanzhen-jian",130);  //ȫ�潣
        set_skill("dodge", 110);
        set_skill("jinyan-gong", 120);   //���㹦
        set_skill("parry", 140);
        set_skill("unarmed",150);
        set_skill("haotian-zhang", 150);    //�����
        set_skill("literate",100);
        set_skill("strike",120);
        set_skill("taoism",100);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
       
     
}
#include "/quest/guanfu/npc/npc.h"

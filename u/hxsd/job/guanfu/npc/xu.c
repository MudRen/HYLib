// xu �쳤��
 
inherit NPC;
 
void create()
{
	set_name("�쳤��", ({ "xu zhanglao", "xu" }));
	set("nickname", "ؤ����ͽ");
	set("long", 
        "ؤ�����ͽ����˵ؤ����������Ĵ���̽�����ټ���\n");
	set("gender", "����");
	set("age", 66);
	set("attitude", "peaceful");
	set("shen", -85000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 850000); 
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "force.powerup" :),
         })); 
         set_skill("force", 160);
         set_skill("huntian-qigong", 150);
         set_skill("dodge", 150);
  

        set_skill("xiaoyaoyou", 160);
        set_skill("cuff", 160);
        set_skill("wenjia-quan", 150);
        set_skill("parry", 150);
        set_skill("xiaoyao-dao", 160);
        set_skill("blade", 150);
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("blade", "xiaoyao-dao");
        map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "xiaoyao-dao");
  	prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"blade")->wield(); 
        add_money("gold", 3);
}
#include "/quest/guanfu/npc/npc.h"

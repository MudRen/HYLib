// yuan Ԫ�㲨
 
inherit NPC;
 
void create()
{
	set_name("Ԫ�㲨", ({ "yuan guangpo", "yuan" }));
	set("nickname", "��ɰ�����");
	set("long", 
        "��ɰ��İ��������غ��ش���ҽ��ᣬ�����ˡ�\n");
	set("gender", "����");
	set("age", 46);
	set("attitude", "peaceful");
	set("shen", -5000);
	set("str", 28);
	set("int", 20);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 1800);
	set("max_neili", 1800);
	set("jiali", 100);
	set("combat_exp", 550000); 
	 
         set_skill("force", 130);
         set_skill("huntian-qigong", 130);
         set_skill("dodge", 130);
  

        set_skill("xiaoyaoyou", 130);
        set_skill("cuff", 150);
        set_skill("jingang-quan", 120);
        set_skill("parry", 130);
        set_skill("wenjia-daofa", 130);
        set_skill("blade", 130);
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("blade", "wenjia-daofa");
        map_skill("cuff", "wenjia-quan");
  	map_skill("parry", "wenjia-daofa");
  	prepare_skill("cuff", "wenjia-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"blade")->wield(); 
        add_money("silver", 50);
}
#include "/quest/guanfu/npc/npc.h"

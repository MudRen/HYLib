// NPC :wu_guangsheng.c ���ʤ
// By River 98/12
inherit NPC;
void create()
{
        set_name("���ʤ", ({ "wu guangsheng", "wu", "guangsheng"}));
        set("title","���������ڵ���");              
        set("gender", "����" );
        set("age", 36);
        set("str", 27);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 15);
   	set("attitude", "friendly");

        set("max_qi", 1000);
        set("max_jing", 800);
        set("eff_jingli", 800);
        set("neili", 1000);
	set("qi", 1000);	
        set("max_neili", 1000);      
        set("unique", 1);
        
        set("long","�������������ڵĵ��ӡ�\n");
        set("combat_exp", 200000);
        set("shen", 800); 

        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("cuff", 80);
        set_skill("sword", 80);
        set_skill("kurong-changong", 80);   
        set_skill("xiaoyaoyou", 80);
        set_skill("wuliang-jianfa", 80);
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuliang-jianfa");
        map_skill("sword", "wuliang-jianfa");
        map_skill("force", "kurong-changong");         

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/changpao")->wear();
}

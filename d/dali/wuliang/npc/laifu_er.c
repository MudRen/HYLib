// NPC :laifu_er.c ������ 
// By River 98/12
inherit NPC;
void create()
{
        set_name("������", ({ "laifu er", "laifu", "er"}));
        set("title","��ٹȼ���");                
        set("gender", "����" );
        set("age", 33);
        set("str", 17);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 14);
   	set("attitude", "friendly");

        set("max_qi", 500);
        set("max_jing", 300);
        set("eff_jingli", 300);
        set("neili", 500);
	set("qi", 500);	
        set("max_neili", 500);      
        set("unique", 1);
        
        set("long","һ������ʵʵ���ˣ��Ѿ�����ٹ��ж����ˡ�\n");
        set("combat_exp", 50000);
        set("shen", 0); 

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50); 

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

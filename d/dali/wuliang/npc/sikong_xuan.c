// NPC :sikong_xuan.c ˾����
// By River 98/12
inherit NPC;
void create()
{
        set_name("˾����", ({ "sikong xuan", "sikong", "xuan"}));
        set("title","��ũ�����"); 
        set("gender", "����" );
        set("age", 56);
        set("str", 27);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 20);
        set("attitude", "heroism");

        set("max_qi", 1800);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("neili", 2000);
        set("qi", 1800);        
        set("max_neili", 2000);
        set("jiali", 40);
        set("unique", 1);
        
        set("long","������ũ����������һ��ɽ����ӣ���̬�����ư���\n");
        set("combat_exp", 400000);
        set("shen", -1000); 

        set_skill("parry", 120);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("kurong-changong", 100);   
        set_skill("feixing-shu", 100);
        set_skill("chousui-zhang", 100);
        map_skill("dodge", "feixing-shu");
        map_skill("parry", "chousui-zhang");
        map_skill("strike", "chousui-zhang");
        map_skill("force", "kurong-changong");
        prepare_skill("strike", "chousui-zhang");

        setup(); 
        carry_object("/clone/misc/cloth")->wear();
}


// shibowei.c ʷ����

inherit NPC;
 
void create()
{
        set_name("ʷ����", ({ "shi bowei","shi", "bowei" }));
        set("nickname", "�׶�ɽ��");
        set("long", 
        "��������ɽׯ���ֵܵĴ�磬��Ŀ��࣬��ɫ΢�ڡ�\n"
        "��˵һ�����ޱ�������뻯��\n");
        set("gender", "����");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen", 4500);
        set("str", 25);
        set("int", 18);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 50);
        set("combat_exp", 450000);
         
    set_skill("force", 90);
    set_skill("hunyuan-yiqi", 90);
    set_skill("dodge", 90);
    set_skill("shaolin-shenfa", 80);
    set_skill("cuff", 90);
    set_skill("jingang-quan", 80);
    set_skill("parry", 90); 
    set_skill("literate", 20);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "jingang-quan");
    map_skill("parry", "jingang-quan");
    prepare_skill("cuff", "jingang-quan");

         set("inquiry", ([
                "�����" : "���ܵĲ�ȫ�������˼Ҳŵ��Կ�����",
                "����" : "��Ҫ�����Ǹ�������һ��Ҫɱ������",
              
                
        ]) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
// shizhongmeng.cʷ����

inherit NPC;
 
void create()
{
        set_name("ʷ����", ({ "shi zhongmeng","shi","zhongmeng" }));
        set("nickname", "�ܼ���");
        set("long", 
        "��������ɽׯ���ֵܵ��϶��������ʵ������������\n"
        "�ó�����Ұ�ޡ�\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen", 4300);
        set("str", 28);
        set("int", 16);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 800);
        set("max_jing", 700);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 50);
        set("combat_exp", 430000);
         
    set_skill("force", 80);
    set_skill("yinyun-ziqi", 80);
    set_skill("dodge", 80);
    set_skill("tiyunzong", 80);
    set_skill("hand", 80);
    set_skill("juehu-shou", 80);
    set_skill("parry", 80);
    set_skill("literate", 50);

    map_skill("force", "yinyun-ziqi");
    map_skill("dodge", "tiyunzong");
    map_skill("hand", "juehu-shou");
    map_skill("parry", "juehu-shou");
    prepare_skill("hand", "juehu-shou");

         set("inquiry", ([
                "�����" : "���ܵĲ�ȫ�������˼Ҳŵ��Կ�����",
                "����" : "��Ҫ�����Ǹ�������һ��Ҫɱ������",
                "����": "�˼�Ϊ�����ֵ��洫֮�����书����С�ɣ�ѧϰ����Σ�ա�",
                
        ]) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 1);
}
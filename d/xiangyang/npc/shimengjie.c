// shimengjie.cʷ�Ͻ�

inherit NPC;
 
void create()
{
        set_name("ʷ�Ͻ�", ({ "shi mengjie","shi","mengjie" }));
        set("nickname", "������Գ");
        set("long", 
        "��������ɽׯ���ֵܵ���Сһ��������һ�������ȴ�ǳ���ɫ��\n");
        set("gender", "����");
        set("age", 24);
        set("attitude", "peaceful");
        set("shen", 6500);
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 21);
        
        set("max_qi", 1000);
        set("max_jing", 900);
        set("neili", 1100);
        set("max_neili", 1100);
        set("jiali", 50);
        set("combat_exp", 500000);
        
    set_skill("force", 105);
    set_skill("hunyuan-yiqi", 105);
    set_skill("dodge", 90);
    set_skill("blade", 90);
    set_skill("xiuluo-dao", 90);
    set_skill("shaolin-shenfa", 90);
    set_skill("cuff", 90);
    set_skill("jingang-quan", 90);
    set_skill("parry", 90);
    set_skill("literate", 50);

        map_skill("force", "hunyuan-yiqi");
        map_skill("blade", "xiuluo-dao");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "xiuluo-dao");
        prepare_skill("cuff", "jingang-quan");

         set("inquiry", ([
                "�����" : "����ȫ�������˼ҵ����˲ŵ��Կ�����",
                "����" : "��Ҫ�����Ǹ�������һ��Ҫɱ������",
                "����": "�˼�Ϊ�����ֵ��洫֮�����书����С�ɣ�ѧϰ����Σ�ա�",
                
        ]) );
        
        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 1);
}
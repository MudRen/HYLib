// shijiqiang.cʷ��ǿ

inherit NPC;
 
void create()
{
        set_name("ʷ��ǿ", ({ "shi jiqiang","shi", "jiqiang" }));
        set("nickname", "������");
        set("long", 
        "��������ɽׯ���ֵܵ����ģ���������,�������\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen", 4000);
        set("str", 36);
        set("int", 15);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 50);
        set("combat_exp", 400000);
        
    set_skill("force", 80);
    set_skill("hunyuan-yiqi", 80);
    set_skill("dodge", 90);
    set_skill("club", 80);
    set_skill("weituo-gun", 80);
    set_skill("shaolin-shenfa", 80);
    set_skill("cuff", 100);
    set_skill("jingang-quan", 90);
    set_skill("parry", 80);

        map_skill("force", "hunyuan-yiqi");
        map_skill("club", "weituo-gun");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "weituo-gun");
        prepare_skill("cuff", "jingang-quan");

         set("inquiry", ([
                "�����" : "����ȫ�������˼ҵ����˲ŵ��Կ�����",
                "����" : "��Ҫ�����Ǹ�������һ��Ҫɱ������",
                "����": "�˼�Ϊ�����ֵ��洫֮�����书����С�ɣ�ѧϰ����Σ�ա�",
                
        ]) );
        
        setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 1);
}
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("�η���", ({ "ren feiyan", "ren", "feiyan"}));
        set("gender", "Ů��");
        set("age", 25);
        set("attitude", "peaceful");
        set("unique", 1);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 10);
        set("max_qi",1200);
        set("max_jing",800);
        set("combat_exp", 600000);
        set("shen_type", 1);

        set_skill("force", 140);             // �����ڹ�
        set_skill("huntian-qigong", 140);    // ��������
        set_skill("blade", 140);             // ��������
        set_skill("wuhu-duanmendao", 140);
//      set_skill("fuqi-daofa", 180);        // ���޵���
        set_skill("dodge", 140);             // �����Ṧ
        set_skill("xiaoyaoyou", 140);        // ��ң��
        set_skill("parry", 140);             // �����м�
        
        map_skill("force", "huntian-qigong");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuhu-duanmendao");
     
        setup();

        carry_object("/clone/weapon/gangdao")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/jinchai")->wear();        
        add_money("silver",10);
}


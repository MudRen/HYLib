// gslve.c ��������
// By River 99/05/20
inherit NPC;
void create()
{
        set_name("��������", ({ "gongsun lve", "gongsun", "lve" }));
        set("long", "��üĿ���ţ������峺����ɫ���ﷺ�죬��Ǳ�����СС���롣����ȥ����һ������֮����\n");
        set("title","����ȹ���֮Ů");
        set("gender", "Ů��");
        set("age", 18);
        set("attitude", "friendly");
        set("shen", 1000);
        set("str", 25);
        set("int", 24);
        set("con", 28);
        set("dex", 26);
        set("per", 29);
        set("unique",1);

        set("max_qi", 1000);
        set("max_jing", 1200);
        set("neili", 1200);
        set("max_neili", 1200);
        set("eff_jingli",1000);
        set("jiali", 30);
        set("combat_exp", 300000);

        set_skill("force", 100);      
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("guiyuan-tunafa", 100);
        set_skill("literate", 120); 
        set_skill("shuishangpiao", 100);
        set_skill("tiezhang-zhangfa", 100);
        set_skill("strike",100);
        set_skill("sword", 100);
	set_skill("liangyi-jian", 100);

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([
            "���鵤": "��ҩ����ֻ�������ˣ������Ҹ����ղصĺ����ܡ�",
            "�黨": "��Щ��������ģ��������ж��ġ�",
        ]) );
        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

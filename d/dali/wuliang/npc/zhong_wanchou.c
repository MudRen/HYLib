// NPC :zhong_wanchou.c ����� 
// By River 98/12
inherit NPC;
void create()
{
        set_name("�����", ({ "zhong wanchou", "zhong", "wanchou"}));
        set("title","��ٹȹ���");
        set("nickname","������");
        set("gender", "����" );
        set("age", 42);
        set("str", 26);
        set("con", 23);
        set("dex", 22);
        set("int", 10);
        set("per", 5);
   	set("attitude", "heroism");

        set("max_qi", 1800);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("neili", 2000);
	set("qi", 1800);	
        set("max_neili", 2000);
        set("jiali", 40);
        set("unique", 1);
        
        set("long","ֻ�����ó�һ���������۾��������ߣ�һ��԰԰�Ĵ����ȴ����ͼ���һ�顣\n");
        set("combat_exp", 400000);
        set("shen", -1000); 

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("kurong-changong", 100);        
        set_skill("tiannan-step", 100);
        set_skill("kunlun-zhang", 100);
        map_skill("dodge", "tiannan-step");
        map_skill("parry", "kunlun-zhang");
        map_skill("strike", "kunlun-zhang");
        map_skill("force", "kurong-changong");
        prepare_skill("strike","kunlun-zhang");

        set("inquiry", ([            
//            "������" : (: ask_duan :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

// huajy.c ����Ӱ
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����Ӱ", ({"Hua jianying", "hua", "jianying"}));
	set("title", HIY"̫������"NOR);
	set("nickname", "���Ǹ���");
        set("shen_type", 1);
	set("gender", "����");
	set("age", 36);
	set("long", 
"���˿������е���ģ��׾���Ƥ��������һ�������������һ��
��һ����ͷ�����˰�磬���������һλ��òӢ���������������
����һ�����Ǵ���\n"
	);

	set("attitude", "aggressive");
        set("vendetta/authority",1);
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("max_qi", 500);
	set("qi", 500);
	set("max_jing",500);
	set("eff_jing", 500);
        set("jingli", 800);
        set("eff_jingli", 800);        
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 1);
	
	set("combat_exp", 90000);
	
	set_skill("force", 60);		
	set_skill("huntian-qigong", 60);	
	set_skill("dodge", 60);	
	set_skill("hammer", 90);		
	set_skill("parry", 60);			
		
	map_skill("force", "huntian-qigong");

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/liuxing-chui")->wield();
} 

// changcf.c ������
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������", ({"chang changfeng", "chang", "changfeng"}));
	set("title", HIY"̫������"NOR);
	set("nickname", "˫�ƿ���");
        set("shen_type", 1);
	set("gender", "����");
	set("age", 35);
	set("long", 
"���˿������ָ��ַʣ�������һ���������ڵ��£�����ǰ����һ
���ʯ��������д���ǡ��ȿ��Ƹ����ϱ�֮Ĺ����\n"
	);

	set("attitude", "aggressive");
        set("vendetta/authority",1);
	
	set("max_qi", 500);
	set("qi", 500);
	set("jing",500);
	set("max_jing", 500);
        set("jingli", 600);
        set("eff_jingli", 600);        
	set("neili", 500);
	set("max_neili", 900);
	set("jiali", 1);
	set("str",40);
	set("combat_exp", 90000);
	
	set_skill("force", 60);		
	set_skill("huntian-qigong", 60);	
	set_skill("dodge", 60);	
	set_skill("hammer", 90);		
	set_skill("parry", 60);			
		
	map_skill("force", "huntian-qigong");

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/mubei")->wield();
} 

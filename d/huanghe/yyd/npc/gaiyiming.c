// gaiyiming.c ��һ��
// zly 7/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��һ��", ({"gai yiming", "gai", "yiming"}));
	set("title", HIY"̫������"NOR);
	set("nickname", "�˲��ϲ�����ר�̤ѩ�޺ۡ�����ˮ�Ϸɡ�˫�̸���ʡ");
        set("shen_type", 1);
	set("gender", "����");
	set("age", 36);
	set("long", 
"���˿�������С�������°ͼ�������������һ�Զ�ü�ִ̡�\n"
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
	
	set("combat_exp", 90000);
	
	set_skill("force", 60);		
	set_skill("huntian-qigong", 60);	
	set_skill("dodge", 60);	
	set_skill("sword", 90);		
	set_skill("parry", 60);			
		
	map_skill("force", "huntian-qigong");

        set("chat_chance", 3);
        set("chat_msg", ({
            "��һ��һ�ڶ��Ҵ̣�ϸ��ϸ���ص���������ʲô�������͸��������°ɣ���\n",
            "��һ��˵�����������ֵ����������������壬ר�ų�ǿ�������ٸ�
��ƶ���������˳ƴ��������ġ�̫������������\n", 
     }) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();

} 

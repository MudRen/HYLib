// zhou.c ������
// modified by zly 6/6/99

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������", ({"zhou", "weixing", "xing"}));
	set("title", "�����ھֵ�����ͷ");
	set("nickname", "������˷�");
        set("shen_type", -1);
	set("gender", "����");
	set("age", 58);
	set("long", 
		"�����ͷ����������֪�����������������ھֵ�����ͷ����������һ�㶼�����ۡ�\n"
		"�����ְ����������ޣ�����ؿ������ܡ�\n"
	);

	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 100);
	
	set("combat_exp", 150000);
	
	set_skill("force", 200);		
	set_skill("huntian-qigong", 200);	
	set_skill("dodge", 200);			
	set_skill("xiaoyaoyou", 200);		
	set_skill("parry", 200);			
	set_skill("whip", 200);		
	set_skill("yunlong-bian", 200);
		
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "yunlong-bian");
        map_skill("whip","yunlong-bian");
	set("chat_chance", 3);
	set("chat_msg", ({
	"���µ�����أ�û�������������밲������ʧ��Ҫ�������ˡ�\n"
	"����������˵�������������Ե����̵�һʱ֮�����������֮�֡��� \n",
	"�����ŵ�����: �����������Ե������鲻���֣����ֲ����顱��\n",
        "������С�����������������Ե���ֻҪ���ֶ࣬��¥̧���ӡ���\n",
	}));   
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changbian")->wield();

} 



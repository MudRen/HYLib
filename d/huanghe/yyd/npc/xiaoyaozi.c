// xiaoyaozi.c ��ң��
// zly 7/6/99

#include <ansi.h>
inherit NPC;
string ask_yaoshi();

void create()
{
	set_name("��ң��", ({"xiaoyao zi", "zi", "xiaoyao"}));
	set("title", HIY"̫������"NOR);
	set("nickname", "��ϼ����");
        set("shen_type", 1);
	set("gender", "����");
	set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("age", 38);
	set("long", 
"����һ������ģ���������ˣ��������ڣ�ҧ��һ�����̹ܣ�˫Ŀ
�����Ʊգ�����������������\n"
	);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

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
	set_skill("stick" ,90);	
	set_skill("dodge", 60);			
	set_skill("parry", 60);			
		
	map_skill("force", "huntian-qigong");

        set("chat_chance", 3);
        set("chat_msg", ({
            "��ң�Ӻٺ�Ц�ŵ������������������Ҫ�úõز���...��˵�꣬��������������ܡ�\n",
        }) );

        set("inquiry", ([
           "Կ��"  : (: ask_yaoshi :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/yanguan")->wield();
        carry_object(__DIR__"obj/shoes")->wear();        
       

} 

string ask_yaoshi()
{
        object me=this_player();
        me->set_temp("tao",1);
        command("hehe");
        command("whisper "+me->query("id")+" ������Ҳ���������ġ�");
        return "˵�꣬͵͵���ɽ�Ǳ�����һ�ۡ�\n";
}


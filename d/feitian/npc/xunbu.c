// guard.c

#include <ansi.h>

inherit NPC;
int do_catch(object ob);

void create()
{
	set_name("��������",({"xunbu"}));

	set("nickname","�ΰ�����");
	set("title","����");
	set("gender", "����" );
	set("age",25);
	set("long",
	"�ձ������Ĵ��������ӡ�����û��ǲ�Ҫ��������\n"
	);
	set("pursuer",1);
	set("attitude", "heroism");
	setup();
        carry_object(__DIR__"obj/wushidao")->wield();
}


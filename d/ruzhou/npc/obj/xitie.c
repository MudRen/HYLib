//Obj: /d/ruzhou/npc/obj/xitie.c  ϲ�����μӻ�������
// llm 99/07

inherit ITEM;

void create()
{
	set_name("ϲ��", ({ "xi tie","tie"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
   {
		set("unit", "��");
		set("long","һ�Ŵ������ӣ�����д�ţ�\n"
			"�������²μ����ǵ������ݺ���ׯ�Ļ��������ӭ��¥�Ļ��硣\n");
      set("material", "paper");
	}
	setup();
}


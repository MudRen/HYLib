// Room: /d/yandang/luoyan14
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
���в��õ�ʮ�־���,���ⴰǰ��̴ľ���ϰ���һ�������,��
ɫ��Ҷ�Ӵ�����,һ��ˮ�����ƺ�Ҫ������,��ϸ��,�ŷ�����������
�����������ȥ��.�����ǽ�Ϲ���һ�ѳ¾ɵ��ƽ�,���������ŵ�
�첼��¶��һ˿Ѫ��.��˵�ǰ���ǰ��ʥ������.
LONG);

  set("sword", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan13",
]));

  setup();
}
void init()
{
	add_action("do_get", "get");
}

int do_get(string arg)
{
    object me,ob1;
    me=this_player();

    if ( (arg!="sword")&&(arg!="��")) return 0;
if (!query("sword")) return notify_fail("ǽ�ϵĽ��Ѿ�����ȡ����!\n");
if((me->query("family/family_name")=="�㵴��")&&(query("sword")))
    {message_vision(
"$N��ǽ��ȡ��һ����˫�񽣣�\n", me);
      		 ob1=clone_object(__DIR__"obj/wushuang.c");
			 ob1->move(me);
        set("sword",0);
        return 1;
}
return 0;
}

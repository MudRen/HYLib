
// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "�����ַ��ֵ�");
    set("long", @LONG
�����ǳ�����һ�����������ֳ�������ҹĻ���ٺ�����͸���
���֡����������Ŀ����д�ٹ��ˣ��������������ã��˼����ĵ���
�ӣ������Ⱥ�ı�ʿ����ʱҲ�ܿ���һЩ���׿ʹ���ɮ�˻��ʿ��
LONG);
    set("exits", ([
       "west" :__DIR__"ca12",
//       "up" :__DIR__"yuefang",
]));
        set("objects", ([
          __DIR__"npc/yuezi" : 1,
]));
    setup();
    replace_program(ROOM);
}

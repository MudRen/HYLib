// ������100�����II
// panzi.c ϴ�õ�����
// ����lywin 2000/6/1 ��ͯ��
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "������" , ({"zhangpanzi"}));
        set_weight(3);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ո��ù��������ӡ�\n");
                set("value", 0);
        }
        setup();
}

// by XiaoYao

#include <ansi.h>
inherit ITEM;

void create()
{
     set_name(YEL"ͭԿ��"NOR, ({"tong yaoshi","key", "yaoshi"}));
     set_weight(10);
          if (clonep())
           set_default_object(__FILE__);
     else {
           set("unit", "��");
           set("long", "�⿴�����ƺ���һ�ѹ뷿��Կ�ף�����֪����ʲô�á�\n");
                set("value", 200);
           setup();
          }
}


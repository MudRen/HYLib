inherit F_CLEAN_UP;
int main(object me, string arg)
{
  string cmd,objname;
  object obj;
  if( !arg || arg=="" || sscanf(arg, "%s to %s",objname,cmd)!=2 )
  return notify_fail("����������ʲô��\n");
  seteuid(getuid());
//  obj=LOGIN_D->find_body(objname);
  obj=find_living(objname);
  obj = present(objname, environment(me));
  if(!obj)   obj=find_living(objname);
  if(!obj) return notify_fail("find_body�Ҳ������ǣ�\n");
    if ((int)wiz_level(me) < (int)wiz_level(obj) )  return notify_fail("����Ȩ��"+me->name(1)+"����ʩ�\n");
  obj->force_me(cmd);
  log_file("force_cmds",sprintf("%s force %s to %s",me->short(1),obj->short(1),cmd));
  return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ:force sb. doing sth.
HELP
    );
    return 1;
}

